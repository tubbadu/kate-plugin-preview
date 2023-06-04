# CMake generated Testfile for 
# Source directory: /home/tubbadu/code/kate-plugin/markdown-preview
# Build directory: /home/tubbadu/code/kate-plugin/markdown-preview/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(appstreamtest "/usr/bin/cmake" "-DAPPSTREAMCLI=/usr/bin/appstreamcli" "-DINSTALL_FILES=/home/tubbadu/code/kate-plugin/markdown-preview/build/install_manifest.txt" "-P" "/usr/share/ECM/kde-modules/appstreamtest.cmake")
set_tests_properties(appstreamtest PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;165;add_test;/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;183;appstreamtest;/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;0;;/home/tubbadu/code/kate-plugin/markdown-preview/CMakeLists.txt;9;include;/home/tubbadu/code/kate-plugin/markdown-preview/CMakeLists.txt;0;")
