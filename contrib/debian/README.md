
Debian
====================
This directory contains files used to package ailed/aile-qt
for Debian-based Linux systems. If you compile ailed/aile-qt yourself, there are some useful files here.

## aile: URI support ##


aile-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install aile-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your aile-qt binary to `/usr/bin`
and the `../../share/pixmaps/aile128.png` to `/usr/share/pixmaps`

aile-qt.protocol (KDE)

