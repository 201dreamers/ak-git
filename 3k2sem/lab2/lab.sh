#!/usr/bin/env bash

PATH=~/opt/xpack-qemu-arm-2.8.0-12/bin:$PATH
case $1	in
	"build")
		make target
		;;
	"run")
		make qemu
		;;
	"clean")
		make clean
		;;
esac
