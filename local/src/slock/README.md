# slock - simple screen locker

`simple` screen locker utility for `X`.


## Features & Patches

- [capscolor](https://tools.suckless.org/slock/patches/capscolor/): Introduces an additional color to indicate the state of Caps Lock.
- [message](https://tools.suckless.org/slock/patches/message/): Add a message to your lock screen.

## Requirements

In order to build `slock` you need the `Xlib` header files.


## Installation

Edit `config.mk` to match your local setup (`slock` is installed into the `/usr/local` namespace by default).

Afterwards enter the following command to build and install `slock` (if necessary as root):

```bash
make clean install
```

## Running

Simply invoke the `slock` command. To get out of it, enter your `password`.
