#!/bin/bash

# Usage : ./vlcCocketPlayer.sh vlcCommand
echo -n "$*" | nc -U /tmp/vlc.sock
