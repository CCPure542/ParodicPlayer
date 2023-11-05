#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::dragEnterEvent(QDragEnterEvent * ev)
{
    if (ev->mimeData()->hasUrls())
    {
        ev->acceptProposedAction();
    }
}
void MainWindow::dropEvent(QDropEvent * ev)
{
    if (ev->mimeData()->hasUrls())
    {
        QStringList paths;
        for (const QUrl &url : ev->mimeData()->urls())
        {
            paths.append(url.toLocalFile());
        }
        emit this->filesDropped(paths);
    }
}
