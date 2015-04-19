#include <pluginlib/class_list_macros.h>

#include "flobotics_finger_rviz_controller.h"

#include <flobotics_finger_messages/flobotics_finger_control_values.h>

namespace flobotics_finger_rviz_controller {

bool a=0;

  FloboticsFingerControlPanel::FloboticsFingerControlPanel(QWidget* parent):
      rviz::Panel(parent)
  {
    _vbox = new QVBoxLayout();
    _hbox0 = new QHBoxLayout();

    _button_start_drawback = new QPushButton(tr("Start Drawback"));
    _button_stop_drawback = new QPushButton(tr("Stop Drawback"));
    _button_start_proximal_1_drawback = new QPushButton(tr("Start Proximal 1 Drawback"));
    _button_start_proximal_2_drawback = new QPushButton(tr("Start Proximal 2 Drawback"));
    _button_start_intermediate_drawback = new QPushButton(tr("Start Intermediate Drawback"));
    _button_start_distal_drawback = new QPushButton(tr("Start Distal Drawback"));

    _hbox0->addWidget(_button_start_drawback);
    _hbox0->addWidget(_button_stop_drawback);
    _hbox0->addWidget(_button_start_proximal_1_drawback);
    _hbox0->addWidget(_button_start_proximal_2_drawback);
    _hbox0->addWidget(_button_start_intermediate_drawback);
    _hbox0->addWidget(_button_start_distal_drawback);

    _vbox->addLayout(_hbox0, 1);

    setLayout(_vbox);

    connect(_button_start_drawback, SIGNAL(clicked()), this, SLOT (start_drawback()));
    connect(_button_stop_drawback, SIGNAL(clicked()), this, SLOT (stop_drawback()));
    connect(_button_start_proximal_1_drawback, SIGNAL(clicked()), this, SLOT (start_proximal_1_drawback()));
    connect(_button_start_proximal_2_drawback, SIGNAL(clicked()), this, SLOT (start_proximal_2_drawback()));
    connect(_button_start_intermediate_drawback, SIGNAL(clicked()), this, SLOT (start_intermediate_drawback()));
    connect(_button_start_distal_drawback, SIGNAL(clicked()), this, SLOT (start_distal_drawback()));

    start_drawback_publisher_ = nh_.advertise<flobotics_finger_messages::flobotics_finger_control_values>("flobotics_finger_control", 10 );
  }


  void FloboticsFingerControlPanel::start_drawback()
  {
    flobotics_finger_messages::flobotics_finger_control_values msg;
    msg.mode = 2;

    start_drawback_publisher_.publish(msg);
  }

  void FloboticsFingerControlPanel::stop_drawback()
  {
    flobotics_finger_messages::flobotics_finger_control_values msg;
    msg.mode = 0;

    start_drawback_publisher_.publish(msg);
  }

  void FloboticsFingerControlPanel::start_proximal_1_drawback()
  {
    flobotics_finger_messages::flobotics_finger_control_values msg;
    msg.mode = 3;

    start_drawback_publisher_.publish(msg);
  }

  void FloboticsFingerControlPanel::start_proximal_2_drawback()
    {
    flobotics_finger_messages::flobotics_finger_control_values msg;
      msg.mode = 4;

      start_drawback_publisher_.publish(msg);
    }

  void FloboticsFingerControlPanel::start_intermediate_drawback()
    {
    flobotics_finger_messages::flobotics_finger_control_values msg;
      msg.mode = 5;

      start_drawback_publisher_.publish(msg);
    }

  void FloboticsFingerControlPanel::start_distal_drawback()
    {
    flobotics_finger_messages::flobotics_finger_control_values msg;
      msg.mode = 6;

      start_drawback_publisher_.publish(msg);
    }
}

PLUGINLIB_EXPORT_CLASS(flobotics_finger_rviz_controller::FloboticsFingerControlPanel, rviz::Panel)
