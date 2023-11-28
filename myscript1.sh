#!/bin/bash

BDIR=/backup
FILENAME=$BDIR/$(hostname)

tar -cvzf $FILENAME.tar.gz -C /home/atg/Documents . &> $FILENAME.log
