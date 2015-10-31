// mainwindow.cpp
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

#include "mainwindow.hpp"
#include <QMainWindow>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QTabWidget>

namespace qe {
  MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("QutesEdit");
    /* Menubar */
    menubar = new QMenuBar();
    file_menu = new QMenu("File", this);
    edit_menu = new QMenu("Edit", this);
    search_menu = new QMenu("Search", this);
    extras_menu = new QMenu("Extras", this);
    help_menu = new QMenu("Help", this);
    menubar->addMenu(file_menu);
    menubar->addMenu(edit_menu);
    menubar->addMenu(search_menu);
    menubar->addMenu(extras_menu);
    menubar->addMenu(help_menu);
    setMenuBar(menubar);
    /* Tool & status bar */
    toolbar = new QToolBar();
    addToolBar(toolbar);
    statusbar = new QStatusBar();
    setStatusBar(statusbar);
    /* Actions */
    file_new_menu = new QMenu("New...", this);
    new_file_action = new QAction("New file", this);
    new_string_action = new QAction("New string", this);
    open_action = new QAction("Open...", this);
    save_action = new QAction("Save", this);
    save_as_action = new QAction("Save as...", this);
    close_action = new QAction("Close", this);
    exit_action = new QAction("Exit", this);
    file_menu->addMenu(file_new_menu);
    file_new_menu->addAction(new_file_action);
    file_new_menu->addAction(new_string_action);
    file_menu->addAction(open_action);
    file_menu->addAction(save_action);
    file_menu->addAction(save_as_action);
    file_menu->addAction(close_action);
    file_menu->addSeparator();
    file_menu->addAction(exit_action);
    // INFO(31.10.2015, jan): create own class for the tab widget. we will modify it.
    QTabWidget *tw = new QTabWidget();
    setCentralWidget(tw);
  }
  MainWindow::~MainWindow() {
    // Destructor.
  }
}