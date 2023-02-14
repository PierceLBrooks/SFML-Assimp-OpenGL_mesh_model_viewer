#!/bin/sh

python3 -m pip install buildster
python3 -m buildster ./Project.xml BUILDSTER_VARIANT=$1

