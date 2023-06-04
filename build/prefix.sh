export PATH=/home/tubbadu/kde/usr/bin:$PATH

# LD_LIBRARY_PATH only needed if you are building without rpath
# export LD_LIBRARY_PATH=/home/tubbadu/kde/usr/lib64:$LD_LIBRARY_PATH

export XDG_DATA_DIRS=/home/tubbadu/kde/usr/share:${XDG_DATA_DIRS:-/usr/local/share/:/usr/share/}
export XDG_CONFIG_DIRS=/home/tubbadu/kde/usr/etc/xdg:${XDG_CONFIG_DIRS:-/etc/xdg}

export QT_PLUGIN_PATH=/home/tubbadu/kde/usr/lib64/plugins:$QT_PLUGIN_PATH
export QML2_IMPORT_PATH=/home/tubbadu/kde/usr/lib64/qml:$QML2_IMPORT_PATH

export QT_QUICK_CONTROLS_STYLE_PATH=/home/tubbadu/kde/usr/lib64/qml/QtQuick/Controls.2/:$QT_QUICK_CONTROLS_STYLE_PATH
