#include <QApplication>
#include <QMainWindow>
#include "../src/qts/qts.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Qts::Engine *engine = new Qts::Engine();
  QMainWindow window;
  // Should set the window title to "Datei".
  window.setWindowTitle(engine->getValueById(":", "de_DE", "file_menu_nm"));
  window.show();
  return app.exec();
}