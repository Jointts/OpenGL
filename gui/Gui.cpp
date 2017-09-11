//
// Created by Joonas on 03/09/2017.
//

#include <string>
#include <CEGUI/System.h>
#include "Gui.h"
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>
#include <CEGUI/SchemeManager.h>
#include <CEGUI/FontManager.h>

const std::string & CEGUIInstallBasePath = "";

void Gui::initGui() {
    CEGUI::Size *size = new CEGUI::Size(1440, 900);
    CEGUI::OpenGLRenderer openGLRenderer = CEGUI::OpenGLRenderer::bootstrapSystem();
    CEGUI::System::create( openGLRenderer );

    // load schemes


    CEGUI::SchemeManager::getSingleton()::load( "data/schemes/TaharezLook.scheme" );
    CEGUI::SchemeManager::getSingletonPtr();



    // set default font
    CEGUI::Font *font = CEGUI::FontManager::getSingleton().createFont( "data/fonts/Commonwealth-10.font" );
    font->defineFontGlyphs( (CEGUI::utf8*)" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~æøåÆØÅ" );
    CEGUI::System::getSingleton().setDefaultFont( font );
}

void Gui::render() {
    CEGUI::System::getSingleton().renderAllGUIContextdfdsfsdfs();
}

void Gui::createButton() {
    CEGUI::WindowManager &wm = CEGUI::WindowManager::getS();

    // create gui sheet
    CEGUI::Window *sheet = wm.createWindow( "DefaultGUISheet", "root" );
    CEGUI::System::getSingleton().setGUISheet( sheet );

    CEGUI::FrameWindow *fw = (CEGUI::FrameWindow *)wm.createWindow( "WindowsLook/FrameWindow", "mainWindow" );
    sheet->addChildWindow( fw );
    fw->setText( "test framewindow" );
    fw->setMinimumSize( CEGUI::Size( .25f, .25f ) );
    fw->setMaximumSize( CEGUI::Size( .75f, .75f ) );
    fw->setSize( CEGUI::Size( .5f, .5f ) );
    fw->setPosition( CEGUI::Point( .2f, .2f ) );
    fw->setCloseButtonEnabled( false );

    CEGUI::PushButton *pb = (CEGUI::PushButton*)wm.createWindow( "WindowsLook/Button", "mainWindow/testButton" );
    fw->addChildWindow( pb );
    pb->setText( "test button" );
    pb->setMinimumSize( CEGUI::Size( .1f, .1f ) );
    pb->setMaximumSize( CEGUI::Size( .5f, .5f ) );
    pb->setSize( CEGUI::Size( .3f, .3f ) );
    pb->setPosition( CEGUI::Point( .125f, .125f ) );
}