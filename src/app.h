// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>.
#ifndef HEADER_SRC_APP_H_INCLUDED
#define HEADER_SRC_APP_H_INCLUDED

#include <QtCore/QtCore>
#include <QtGui/QtGui>
//#include <Tesla/util/logger.h>
#include <memory> //#include <boost/shared_ptr.hpp>

class App : public QApplication
{
        Q_OBJECT
    public:
        App(int& argc, char** argv);
        ~App();
        
        App* INSTANCE();

        QString getProjectName();
        QString getProjectCodeName();
        QString getProjectVendorID();
        QString getProjectVendorName();
        QString getProjectID();
        int getProjectMajorVersion();
        int getProjectMinorVersion();
        int getProjectPatchVersion();
        QString getProjectVersion();
        QString getProjectCopyrightYears();
        QString getProjectInvocation();
        
    public slots:
        void display();

    private:
        void initGUI();
        void interactiveMain();
        void consoleMain();
    
        void printHelpMessage();
        void printVersionMessage();
        void printVersionTripletMessage();
        void printApplicationIdentifier();
        void setPreference(const std::string& key, const std::string& val);
        void unsetPreference(const std::string& key);
        void printPreference(const std::string& key)const;
        void printAllPreferences()const;
        void setLogLevel(const std::string& logger, const std::string& level);
        std::string getKeyName(const std::string& key)const;
        std::string getKeyRepr(const std::string& key)const;
        std::string convert(const QString& str)const;
        QString convert(const std::string& str)const;
		void setLogger(const char* log_file);
        
        static App* _instance;
        //Logger* _logger = NULL;
        QString _invocation;
        bool _gui;
        bool _interactive;
		std::shared_ptr<QMainWindow> _mainwindow; //boost::shared_ptr<QMainWindow> _mainwindow;
        
        QImage myImage;
        QLabel* render;
        QPushButton *renderbtn;
};

#endif
