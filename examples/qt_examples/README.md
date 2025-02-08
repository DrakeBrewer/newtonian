Contains an example Qt project following a tutorial at https://doc.qt.io/qt-6/qtwidgets-tutorials-widgets-toplevel-example.html
Needs Qt to be installed to run.
To build, run cmake -D CMAKE_PREFIX_PATH=qt_directory, where qt_directory is the path to the Qt directory. In my case, it was home/brendan/Qt/6.8.2/gcc_64. This lets Cmake find the Qt files for building.
