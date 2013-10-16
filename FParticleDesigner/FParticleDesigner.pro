#-------------------------------------------------
#
# Project created by QtCreator 2013-08-29T09:07:48
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FParticleDesigner
TEMPLATE = app

INCLUDEPATH +=  src \
                ../faeris/lib/libfaeris/src \
                ../faeris/lib/lib3rdparty/c99/include \
                ../faeris/lib/lib3rdparty/GL/include \
                ../faeris/lib/lib3rdparty/freetype/include \
                ../faeris/lib/lib3rdparty/libpng/include \
                ../faeris/lib/lib3rdparty/curl/include   \
                ../faeris/lib/lib3rdparty/pthread/include   \




LIBS += -L$$PWD/../faeris/lib/library/win32   -llibfaerisd \
        -L$$PWD/../faeris/lib/library/win32/3rdparty -lglew -llibpng -lfreetype

SOURCES += \
    src/widget/MpTextureSettingWidget.cc \
    src/widget/MpParticleViewWidget.cc \
    src/widget/MpParticleSettingWidget.cc \
    src/widget/MpEnvironmentSettingWidget.cc \
    src/widget/MpEmitterSettingWidget.cc \
    src/main.cpp \
    src/operator/MpAttrOperator.cc \
    src/core/MpProject.cc \
    src/core/MpParticleEffect.cc \
    src/MpGlobal.cc \
    src/MpMsgCenter.cc \
    src/widget/MpMainWindow.cc \
    src/widget/MpProjectExploreWidget.cc \
    src/widget/MpProjectExploreModel.cc \
    src/core/MpIdentify.cc \
    src/operator/MpOperator.cc \
    src/operator/MpDataOperator.cc \
    src/widget/SdInputDialog.cc \
    src/operator/MpUiOperator.cc \
    src/operator/MpIoOperator.cc \
    src/MpConfig.cc \
    src/util/MpPathUtil.cc \
    src/util/SdRenderUtil.cc \
    src/widget/MpAboutDialog.cc

HEADERS  += \
    src/widget/MpPropertyWidget.h \
    src/widget/MpParticleViewWidget.h \
    src/widget/MpParticleSettingWidget.h \
    src/widget/MpEnvironmentSettingWidget.h \
    src/widget/MpEmitterSettingWidget.h \
    src/widget/MpTextureSettingWidget.h \
    src/operator/MpAttrOperator.h \
    src/core/MpProject.h \
    src/core/MpParticleEffect.h \
    src/MpGlobal.h \
    src/MpMsgCenter.h \
    src/widget/MpMainWindow.h \
    src/widget/MpProjectExploreWidget.h \
    src/widget/MpProjectExploreModel.h \
    src/core/MpIdentify.h \
    src/operator/MpOperator.h \
    src/operator/MpDataOperator.h \
    src/operator/MpUiOperator.h \
    src/widget/SdInputDialog.h \
    src/operator/MpIoOperator.h \
    src/MpConfig.h \
    src/util/MpPathUtil.h \
    src/util/SdRenderUtil.h \
    src/util/SdUtil.h \
    src/widget/MpAboutDialog.h

FORMS    += \
    ui/emiter_setting.ui \
    ui/particle_setting.ui \
    ui/environment_setting.ui \
    ui/texture_setting.ui \
    ui/input_text.ui \
    ui/about_fp.ui


