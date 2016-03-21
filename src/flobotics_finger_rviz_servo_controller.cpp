#include <pluginlib/class_list_macros.h>

#include "flobotics_finger_rviz_servo_controller.h"

#include <flobotics_finger_messages/flobotics_finger_servo_control_values.h>

#include "std_msgs/Int16MultiArray.h"


namespace flobotics_finger_rviz_servo_controller {

FloboticsFingerRvizServoController::FloboticsFingerRvizServoController(QWidget* parent):
    rviz::Panel(parent)
{
    _vbox = new QVBoxLayout();
    _hbox0 = new QHBoxLayout();
    _hbox1 = new QHBoxLayout();
    _hbox2 = new QHBoxLayout();
    _hbox3 = new QHBoxLayout();

    _button0 = new QPushButton(tr("0 wind"));
    _button1 = new QPushButton(tr("0 wind up"));
    _button2 = new QPushButton(tr("1 wind"));
    _button3 = new QPushButton(tr("1 wind up"));
    _button4 = new QPushButton(tr("2 wind"));
    _button5 = new QPushButton(tr("2 wind up"));
    _button6 = new QPushButton(tr("3 wind"));
    _button7 = new QPushButton(tr("3 wind up"));
    _button8 = new QPushButton(tr("4 wind"));
    _button9 = new QPushButton(tr("4 wind up"));
    _button10 = new QPushButton(tr("5 wind"));
    _button11 = new QPushButton(tr("5 wind up"));
    _button12 = new QPushButton(tr("6 wind"));
    _button13 = new QPushButton(tr("6 wind up"));
    _button14 = new QPushButton(tr("7 wind"));
    _button15 = new QPushButton(tr("7 wind up"));

    //_button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //_button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    _hbox0->addWidget(_button0);
    _hbox0->addWidget(_button1);
    _hbox0->addWidget(_button2);
    _hbox0->addWidget(_button3);

    _hbox1->addWidget(_button4);
    _hbox1->addWidget(_button5);
    _hbox1->addWidget(_button6);
    _hbox1->addWidget(_button7);

    _hbox2->addWidget(_button8);
    _hbox2->addWidget(_button9);
    _hbox2->addWidget(_button10);
    _hbox2->addWidget(_button11);

    _hbox3->addWidget(_button12);
    _hbox3->addWidget(_button13);
    _hbox3->addWidget(_button14);
    _hbox3->addWidget(_button15);

    _vbox->addLayout(_hbox0, 1);
    _vbox->addLayout(_hbox1, 1);
    _vbox->addLayout(_hbox2, 1);
    _vbox->addLayout(_hbox3, 1);

    setLayout(_vbox);

    signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(_button0, int(0));
    signalMapper->setMapping(_button1, int(1));
    signalMapper->setMapping(_button2, int(2));
    signalMapper->setMapping(_button3, int(3));
    signalMapper->setMapping(_button4, int(4));
    signalMapper->setMapping(_button5, int(5));
    signalMapper->setMapping(_button6, int(6));
    signalMapper->setMapping(_button7, int(7));
    signalMapper->setMapping(_button8, int(8));
    signalMapper->setMapping(_button9, int(9));
    signalMapper->setMapping(_button10, int(10));
    signalMapper->setMapping(_button11, int(11));
    signalMapper->setMapping(_button12, int(12));
    signalMapper->setMapping(_button13, int(13));
    signalMapper->setMapping(_button14, int(14));
    signalMapper->setMapping(_button15, int(15));

    connect(_button0, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button1, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button2, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button3, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button4, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button5, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button6, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button7, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button8, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button9, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button10, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button11, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button12, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button13, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button14, SIGNAL(pressed()), signalMapper, SLOT (map()));
    connect(_button15, SIGNAL(pressed()), signalMapper, SLOT (map()));

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(wind(int)));



    //connect(_button0, SIGNAL(pressed()), this, SLOT(wind(int)));
    connect(_button0, SIGNAL(released()), this, SLOT(stop()));
    connect(_button1, SIGNAL(released()), this, SLOT(stop()));
    connect(_button2, SIGNAL(released()), this, SLOT(stop()));
    connect(_button3, SIGNAL(released()), this, SLOT(stop()));
    connect(_button4, SIGNAL(released()), this, SLOT(stop()));
    connect(_button5, SIGNAL(released()), this, SLOT(stop()));
    connect(_button6, SIGNAL(released()), this, SLOT(stop()));
    connect(_button7, SIGNAL(released()), this, SLOT(stop()));
    connect(_button8, SIGNAL(released()), this, SLOT(stop()));
    connect(_button9, SIGNAL(released()), this, SLOT(stop()));
    connect(_button10, SIGNAL(released()), this, SLOT(stop()));
    connect(_button11, SIGNAL(released()), this, SLOT(stop()));
    connect(_button12, SIGNAL(released()), this, SLOT(stop()));
    connect(_button13, SIGNAL(released()), this, SLOT(stop()));
    connect(_button14, SIGNAL(released()), this, SLOT(stop()));
    connect(_button15, SIGNAL(released()), this, SLOT(stop()));

    //wind_publisher_ = nh_.advertise<flobotics_finger_messages::flobotics_finger_servo_control_values>("pololu_usc01a", 10 );
    wind_publisher_ = nh_.advertise<std_msgs::Int16MultiArray>("servo_pwm_pi_sub", 10);
}

void FloboticsFingerRvizServoController::wind(int servoNr){
  //pub value to topic
  //  flobotics_finger_messages::flobotics_finger_servo_control_values msg;
  std_msgs::Int16MultiArray msg;
  
  //clear array
  msg.data.clear();

  //msg.data.push_back(450);



/*
  msg.servo0 = 64;
  msg.servo1 = 64;
  msg.servo2 = 64;
  msg.servo3 = 64;
  msg.servo4 = 64;
  msg.servo5 = 64;
  msg.servo6 = 64;
  msg.servo7 = 64;
*/

  if(servoNr==0)
    msg.data.push_back(350);
  else if (servoNr==1)
    msg.data.push_back(450);
  else
   msg.data.push_back(4099);  //dont do anything

  if(servoNr==2)
    msg.data.push_back(350);
  else if(servoNr==3)
    msg.data.push_back(450);
  else
    msg.data.push_back(4099); 

  if(servoNr==4)
    msg.data.push_back(350);
  else if(servoNr==5)
    msg.data.push_back(450);
  else
    msg.data.push_back(4099);

  if(servoNr==6)
    msg.data.push_back(350);
  else if(servoNr==7)
    msg.data.push_back(450);
  else
    msg.data.push_back(4099);

  if(servoNr==8)
    msg.data.push_back(350);
  else if(servoNr==9)
    msg.data.push_back(450);
  else
    msg.data.push_back(4099);

  if(servoNr==10)
    msg.data.push_back(350);
  else if(servoNr==11)
    msg.data.push_back(450);
  else
    msg.data.push_back(4099);

  if(servoNr==12)
    msg.data.push_back(350);
  else if(servoNr==13)
    msg.data.push_back(450);
  else
    msg.data.push_back(4099);

  if(servoNr==14)
    msg.data.push_back(350);
  else if(servoNr==15)
    msg.data.push_back(450);
  else
    msg.data.push_back(4099);


  wind_publisher_.publish(msg);
}

void FloboticsFingerRvizServoController::stop(){
  //pub value to topic
  
  std_msgs::Int16MultiArray msg;

  //clear array
  msg.data.clear();

  msg.data.push_back(400);
  msg.data.push_back(400);
  msg.data.push_back(400);
  msg.data.push_back(400);
  msg.data.push_back(400);
  msg.data.push_back(400);
  msg.data.push_back(400);
  msg.data.push_back(400);

/*
  flobotics_finger_messages::flobotics_finger_servo_control_values msg;
  msg.servo0 = 64;
  msg.servo1 = 64;
  msg.servo2 = 64;
  msg.servo3 = 64;
  msg.servo4 = 64;
  msg.servo5 = 64;
  msg.servo6 = 64;
  msg.servo7 = 64;
  msg.servo8 = 64;
  msg.servo9 = 64;
  msg.servo10 = 64;
  msg.servo11 = 64;
  msg.servo12 = 64;
  msg.servo13 = 64;
  msg.servo14 = 64;
  msg.servo15 = 64;
*/
  wind_publisher_.publish(msg);
}

}

PLUGINLIB_EXPORT_CLASS(flobotics_finger_rviz_servo_controller::FloboticsFingerRvizServoController, rviz::Panel)
