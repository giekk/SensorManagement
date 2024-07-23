#include "ctrl.h"

Ctrl::Ctrl(DataManagement* model)
{
    this->model = model;
    this->view = nullptr;
}

void Ctrl::setView(MainWindow* view)
{
    this->view = view;
}