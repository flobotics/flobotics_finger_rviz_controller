#include <QtGui>
#include <QSignalMapper>

#ifndef Q_MOC_RUN
# include <ros/ros.h>
# include <rviz/panel.h>
#endif

namespace flobotics_finger_rviz_servo_controller {

class FloboticsFingerRvizServoController: public rviz::Panel
{
    Q_OBJECT

public:
    FloboticsFingerRvizServoController(QWidget* parent = 0);

signals:
    void pressed(int value);

protected:
    QVBoxLayout* _vbox;
    QHBoxLayout* _hbox0;
    QHBoxLayout* _hbox1;
    QHBoxLayout* _hbox2;
    QHBoxLayout* _hbox3;

    QPushButton* _button0;
    QPushButton* _button1;
    QPushButton* _button2;
    QPushButton* _button3;
    QPushButton* _button4;
    QPushButton* _button5;
    QPushButton* _button6;
    QPushButton* _button7;
    QPushButton* _button8;
    QPushButton* _button9;
    QPushButton* _button10;
    QPushButton* _button11;
    QPushButton* _button12;
    QPushButton* _button13;
    QPushButton* _button14;
    QPushButton* _button15;

    QSignalMapper *signalMapper;

public Q_SLOTS:
    void wind(int servoNr);
    void stop();

protected:
    ros::Publisher wind_publisher_;
    ros::NodeHandle nh_;
};

}
