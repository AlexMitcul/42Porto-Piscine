#!/bin/sh

git log -5 | grep ^commit | cut -d ' ' -f2
