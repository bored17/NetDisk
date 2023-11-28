#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>

#在这个示例中，我们创建了一个名为 CustomSliderWidget 的自定义 QWidget 子类，其中包含一个 QSlider 和一个 QLabel。通过连接 QSlider 的值改变信号到自定义槽函数 onSliderValueChanged，我们能够更新标签以显示滑条的当前值。自定义滑条组件的布局由垂直布局管理。
#这只是一个简单的示例，你可以根据自己的需求扩展自定义滑条组件，例如，你可以添加更多的属性、样式、信号和槽函数，以满足特定的应用程序需求。
#
#
#
#

class CustomSliderWidget : public QWidget {
    Q_OBJECT

public:
    CustomSliderWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // 创建滑条和标签
        slider = new QSlider(Qt::Horizontal);
        label = new QLabel("Value: 50");

        // 设置滑条的范围
        slider->setRange(0, 100);
        slider->setValue(50);

        // 连接滑条的值改变信号到自定义槽函数
        connect(slider, &QSlider::valueChanged, this, &CustomSliderWidget::onSliderValueChanged);

        // 创建垂直布局
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(label);
        layout->addWidget(slider);

        // 设置布局
        setLayout(layout);
    }

private slots:
    void onSliderValueChanged(int value) {
        label->setText("Value: " + QString::number(value));
    }

private:
    QSlider *slider;
    QLabel *label;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建一个主窗口
    QWidget window;
    window.setWindowTitle("自定义滑条示例");
    window.setGeometry(100, 100, 400, 200);

    // 创建自定义滑条组件
    CustomSliderWidget customSlider;
    window.setCentralWidget(&customSlider);

    // 显示主窗口
    window.show();

    return app.exec();
}
