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

#ifndef AUTOLAYOUTITEMSCOMMAND_H
#define AUTOLAYOUTITEMSCOMMAND_H

#include "../../uidatachangingcommand.h"

#include "data/ipipeline.h"
#include "data/iconnection.h"
#include "data/iblock.h"

#include <QMap>

namespace ysm
{
	class PipelineSceneLayouter;

	//! \brief Command that auto layouts a pipeline scene.
	class AutoLayoutItemsCommand : public UIDataChangingCommand
	{

	public:

		/*!
		 * \brief Initialize new instance.
		 * \param pipeline The pipeline.
		 * \param layouter The layouter.
		 */
		AutoLayoutItemsCommand(IPipeline* pipeline, PipelineSceneLayouter* layouter);

		/*!
		 * \brief Execute the command.
		 * \return True, if the command was executed successful.
		 */
		bool execute() Q_DECL_OVERRIDE;

		/*!
		 * \brief Execute the command.
		 * \return True, if the command was undone successful.
		 */
		bool undo() Q_DECL_OVERRIDE;

		/*!
		 * \brief Check if the rendering needs to be re-evaluted after execution.
		 * \return True, if rendering could have changed.
		 */
		bool didChangeRendering() const Q_DECL_OVERRIDE;

	private:

		//! \brief The pipeline.
		IPipeline* _pipeline;

		//! \brief The layouter.
		PipelineSceneLayouter* _layouter;

		//! \brief The new and old position of all items.
		QMap<IPipelineItem*, QPointF> _oldPositions, _newPositions;
	};

}

#endif // AUTOLAYOUTITEMSCOMMAND_H
