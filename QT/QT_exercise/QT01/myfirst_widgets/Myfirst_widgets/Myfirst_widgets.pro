# 在此项目中加入core gui核心（控制台不需要)
# QT是以模块的形式组织类库，根据项目需求不同添加不同类库的支持
QT       += core gui

# 当QT版本大于4，在当前项目中添加widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 都为自动生成的
# 源代码
SOURCES += \
    main.cpp \
    widgets.cpp
# 头文件
HEADERS += \
    widgets.h
# ui文件
FORMS += \
    widgets.ui

# Default rules for deployment.默认部署规则
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
