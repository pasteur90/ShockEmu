#include <IOKit/hid/IOHIDManager.h>
#include <unistd.h>
#include <stdio.h>
#include "zhelpers.h"
#include "gamepad.h"

void *zmq_ctx;
void *publisher;

static void callback(int type, int page, int usage, int value)
{
    char data[50];
    if (usage == 1)
      return;
	/* printf("type=%d, page=%d, usage=%d, value=%d\n", type, page, usage, value); */

    char to_send[] =
    { usage,
      value,
    };

    zmq_send(publisher, to_send, 2, 0);
}



int main()
{
    void* ctx;

    /* initialize gamepad */
    ctx = gamepad_init(1, 0, 0);
    if (!ctx) {
        puts("init failed");
        return -1;
    }
    zmq_ctx = zmq_ctx_new();
    publisher = zmq_socket(zmq_ctx, ZMQ_PUB);
    int rc = zmq_bind(publisher, "tcp://*:54321");
    assert(rc == 0);

    /* set callback */
    gamepad_set_callback(ctx, callback);

    CFRunLoopRun();

    zmq_close(publisher);
    zmq_ctx_destroy(zmq_ctx);

    /* terminate gamepad */
    gamepad_term(ctx);

    return 0;
}
