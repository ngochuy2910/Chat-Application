cmake_minimum_required(VERSION 3.16)

project(Messenger VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appMessenger
    main.cpp
)

qt_add_qml_module(appMessenger
    URI Messenger
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES MainWindow.qml
        QML_FILES Contacts/ContactViews.qml
        QML_FILES Contacts/Components/Background.qml
        RESOURCES Media/Images/background.png Media/Images/avatar.jpg
        QML_FILES Contacts/Components/Header.qml
        QML_FILES OpenedChat/OpenedChatView.qml
        QML_FILES Contacts/Components/ContactList.qml
        QML_FILES Contacts/Components/ContactDelegate.qml
        QML_FILES OpenedChat/Components/ChatHeader.qml
        QML_FILES OpenedChat/Components/ChatInput.qml
        QML_FILES OpenedChat/Components/IconButton.qml
        QML_FILES OpenedChat/Components/Icon.qml
        RESOURCES svg/android.svg svg/apple.svg svg/arrowLeft.svg svg/options.svg svg/search.svg svg/send.svg
        QML_FILES OpenedChat/Components/ChatThread.qml
        QML_FILES OpenedChat/Components/ChatBubble.qml
        RESOURCES Media/Images/hoangvi.jpg
        SOURCES ChatModel.h ChatModel.cpp
        SOURCES
        SOURCES PersonModel.h PersonModel.cpp
        SOURCES Person.h Person.cpp
        SOURCES TcpServer.h TcpServer.cpp
        SOURCES TcpClient.h TcpClient.cpp
        QML_FILES LoginChat/LoginChat.qml
        SOURCES UserProfile.h UserProfile.cpp
        SOURCES AppEngine.h AppEngine.cpp
        SOURCES Adaptor.h Adaptor.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMessenger PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMessenger
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMessenger
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appMessenger
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
