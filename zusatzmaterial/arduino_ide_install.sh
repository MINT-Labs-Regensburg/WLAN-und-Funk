# 1. Create Applications and icons folder
mkdir -p ~/Applications/icons

# 2. Move AppImage from Downloads to Applications
mv ~/Downloads/arduino-ide_*.AppImage ~/Applications/

# 3. Make AppImage executable
chmod +x ~/Applications/arduino-ide_*.AppImage

# 4. Create symlink 'arduino-ide-latest.AppImage' for future updates
cd ~/Applications
rm -f arduino-ide-latest.AppImage
ln -s arduino-ide_*.AppImage arduino-ide-latest.AppImage

# 5. Extract AppImage to get official icon
~/Applications/arduino-ide-latest.AppImage --appimage-extract
cp squashfs-root/usr/share/icons/hicolor/512x512/apps/arduino-ide.png ~/Applications/icons/arduino-ide.png
rm -rf squashfs-root

# 6. Create .desktop file
cat > ~/.local/share/applications/arduino-ide-v2.desktop <<EOF
[Desktop Entry]
Type=Application
Name=Arduino IDE v2
Comment=Open-source electronics prototyping platform
Exec=/home/$USER/Applications/arduino-ide-latest.AppImage --no-sandbox
Icon=/home/$USER/Applications/icons/arduino-ide.png
Terminal=false
Categories=Development;IDE;Electronics;
StartupWMClass=processing-app-Base
EOF

# 7. Make .desktop executable
chmod +x ~/.local/share/applications/arduino-ide-v2.desktop

# 8. Clear GNOME Shell cache
rm -f ~/.cache/gnome-shell/applications/*

# 9. Instructions to reload GNOME Shell
echo "Done! To refresh Show Apps (Xorg): Alt+F2 → r → Enter"
echo "On Wayland, log out and log back in"