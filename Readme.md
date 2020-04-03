[![macos-catalina](https://img.shields.io/badge/macos-catalina-brightgreen.svg)](https://www.apple.com/macos/catalina-preview)
[![macos-mojave](https://img.shields.io/badge/macos-mojave-brightgreen.svg)](https://www.apple.com/lae/macos/mojave)

# What's this program?
This program is useful if you want to use PS4 Remote Play with a __DualShock 3__ controller.

# Credits
All credits should go to https://github.com/daeken and https://github.com/suzukiplan/gamepad-osx.git
If you are happy with my work you can pay me a beer:
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.me/micksoftware)

# Setup
```zsh
git clone https://github.com/MiCkSoftware/ShockEmu.git
cd ShockEmu
./build.sh gamepad.se
./run.sh
```

It depends on your system having [PS4 Remote Play](https://remoteplay.dl.playstation.net/remoteplay/lang/en/index.html) installed at `/Applications/RemotePlay.app`. If this is not the case, you'll need to modify `run.sh` accordingly.

The `OS X Command Line Tools` needs [to be installed](https://stackoverflow.com/a/53078282/584548).

# Key Mapping
`only_keyboard.se` goes like this:

![Key Mapping](https://github.com/MiCkSoftware/ShockEmu/blob/master/KeyMapping.png)

# SE File Format
SE files are, generally speaking, a mapping between an input key, mouse button, or mouse movement to a DualShock 4 input. See the example file (`example.se`) for a breakdown of the format.

# Joystick / Gamepad mapping
57  Hat switch
9   Select
10  Start
1   X
2   B
3   A
4   Y
5   L1
6   R1
7   L2
8   R2
11  T1
12  T2
13  btn5
48  L-1 Axis
49  L-2 Axis
50  R-1 Axis
53  R-2 Axis

# How It Works
ShockEmu works by intercepting the IOHID calls of PS4 Remote Play application and presents an emulated DualShock controller. It also hooks into the input routines of the application, to catch keyboard and mouse inputs, which then get mapped according to your SE file.


