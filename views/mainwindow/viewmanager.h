/***********************************************************************************
 *                                                                                 *
 * quiGLy - quick GL prototyping                                                   *
 *                                                                                 *
 * Copyright (C) 2015-2018 University of Muenster, Germany.                        *
 * Visualization and Computer Graphics Group <http://viscg.uni-muenster.de>        *
 * For a list of authors please refer to the file "CREDITS.txt".                   *
 *                                                                                 *
 * This file is part of the quiGLy software package. quiGLy is free software:      *
 * you can redistribute it and/or modify it under the terms of the GNU General     *
 * Public License version 2 as published by the Free Software Foundation.          *
 *                                                                                 *
 * quiGLy is distributed in the hope that it will be useful, but WITHOUT ANY       *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR   *
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.      *
 *                                                                                 *
 * You should have received a copy of the GNU General Public License in the file   *
 * "LICENSE.txt" along with this file. If not, see <http://www.gnu.org/licenses/>. *
 *                                                                                 *
 * For non-commercial academic use see the license exception specified in the file *
 * "LICENSE-academic.txt". To get information about commercial licensing please    *
 * contact the authors.                                                            *
 *                                                                                 *
 ***********************************************************************************/

#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>

namespace ysm
{
	class MainWindow;

	class MainMenu;
	class MainToolBar;
	class ToolView;
	class LogView;
	class CommandView;
	class PropertyView;
	class RenderView;
	class PipelineView;

	class GLSLEditor;

	//! \brief View manager for the main window.
	class ViewManager : public QObject
	{
		Q_OBJECT

	public:

		/*!
		 * \brief Initialize new instance.
		 * \param parentWindow The parent window.
		 */
		ViewManager(MainWindow* parentWindow);

		/*!
		 * \brief Gets the main menu.
		 * \return The main menu.
		 */
		MainMenu* getMainMenu() const;

		/*!
		 * \brief Gets the pipeline view.
		 * \return The pipeline view.
		 */
		PipelineView* getPipelineView() const;

		/*!
		 * \brief Gets the log view.
		 * \return The log view.
		 */
		LogView* getLogView() const;

	private:

		//! \brief Reference to the main window.
		MainWindow* _parentWindow;

		//! \brief The main menu.
		MainMenu* _menuBar;

		//! \brief The main tool bar.
		MainToolBar* _toolBar;

		//! \brief The tool view.
		ToolView* _toolView;

		//! \brief The command view.
		CommandView* _commandView;

		//! \brief The property view.
		PropertyView* _propertyView;

		//! \brief The render view.
		RenderView* _renderView;

		//! \brief The log view.
		LogView* _logView;

		//! \brief The pipeline view.
		PipelineView* _pipelineView;

		//! \brief The GLSL editor.
		GLSLEditor* _glslEditor;
	};

}

#endif // VIEWMANAGER_H
