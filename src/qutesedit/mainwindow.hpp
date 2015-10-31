// mainwindow.hpp
// Copyright (c) 2015 Jan Kowalewicz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>

class QMenuBar;
class QMenu;
class QToolBar;
class QStatusBar;
class QAction;

namespace qe {
  class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    QMenuBar *menubar;
    QMenu *file_menu;
    QMenu *edit_menu;
    QMenu *search_menu;
    QMenu *extras_menu;
    QMenu *help_menu;
    QToolBar *toolbar;
    QStatusBar *statusbar;
    QMenu *file_new_menu;
    QAction *new_file_action;
    QAction *new_string_action;
    QAction *open_action;
    QAction *save_action;
    QAction *save_as_action;
    QAction *close_action;
    QAction *exit_action;
  };
}

#endif // MAINWINDOW_HPP