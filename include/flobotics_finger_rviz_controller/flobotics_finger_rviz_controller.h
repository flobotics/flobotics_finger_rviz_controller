#include <QtGui>
#include <QSignalMapper>
#include <qlineedit.h>

#ifndef Q_MOC_RUN
# include <ros/ros.h>
# include <rviz/panel.h>
#endif

namespace flobotics_finger_rviz_controller {


class FloboticsFingerControlPanel: public rviz::Panel
{
    Q_OBJECT

public:
    FloboticsFingerControlPanel(QWidget* parent = 0);

signals:
    void pressed(int value);

protected:
    QVBoxLayout* _vbox;
    QHBoxLayout* _hbox0;

    QPushButton* _button_start_drawback;
    QPushButton* _button_stop_drawback;
    QPushButton* _button_start_proximal_1_drawback;
    QPushButton* _button_start_proximal_2_drawback;
    QPushButton* _button_start_intermediate_drawback;
    QPushButton* _button_start_distal_drawback;

public Q_SLOTS:
    void start_drawback();
    void stop_drawback();
    void start_proximal_1_drawback();
    void start_proximal_2_drawback();
    void start_intermediate_drawback();
    void start_distal_drawback();

protected:
    ros::Publisher start_drawback_publisher_;
    ros::NodeHandle nh_;
};

}
