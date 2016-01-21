#!/bin/bash

# Usage : ./vlcCocketPlayer.sh vlcCommand

echo -n "$1" | nc -U /tmp/vlc.sock
