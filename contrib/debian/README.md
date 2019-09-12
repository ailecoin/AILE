
Debian
====================
This directory contains files used to package ailecoind/ailecoin-qt
for Debian-based Linux systems. If you compile ailecoind/ailecoin-qt yourself, there are some useful files here.

## ailecoin: URI support ##


ailecoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install ailecoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your ailecoinqt binary to `/usr/bin`
and the `../../share/pixmaps/ailecoin128.png` to `/usr/share/pixmaps`

ailecoin-qt.protocol (KDE)

