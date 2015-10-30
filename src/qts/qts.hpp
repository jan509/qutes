// qts.h
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

#ifndef QTS_HPP
#define QTS_HPP

#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QFileInfo>

namespace Qts {
  class Engine {
  private:
    QString get(QString filepath, QString id) {
      QString absolute_p(filepath);
      // Lets check if the file exists.
      QFileInfo check(absolute_p);
      if (!check.exists()) {
        // The file doesn't exists. Let's return something the developer can work with.
        return QString("ERR: the specified file (in[QString filepath]) couldn't be found!");
      } else {
        QFile f(absolute_p);
        if (f.open( QIODevice::ReadOnly )) {
          QTextStream in(&f);
          while (!in.atEnd()) {
            QString l = in.readLine();
            QString _id("id(" + id + "): ");
            int pos = l.indexOf(_id);
            if (pos >= 0) {
              QString value = l.mid(pos + _id.length());
              return value;
            }
          }
        }
      }
      return QString();
    }
  public:
    // Gets the value by the specified id (id(id): value).
    QString getValueById(QString path, QString language, QString id) {
      QString filepath(path + "/" + language + ".qtf");
      return get(filepath, id);
    }
    
    // TODO(30.10.2015, jan): implement std::string wrapper.
    // TODO(30.10.1025, jan): implement char wrapper.  
  };
}

#endif // QTS_HPP