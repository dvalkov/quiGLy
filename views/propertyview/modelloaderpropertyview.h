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

#ifndef MODELLOADERPROPERTYVIEW_H
#define MODELLOADERPROPERTYVIEW_H

#include "pipelineitempropertyview.h"

#include <QComboBox>
#include <QLabel>

namespace ysm
{
	//! \brief Custom property view for model loaders.
	class ModelLoaderPropertyView : public PipelineItemPropertyView
	{
		Q_OBJECT

	public:

		/*!
		 * \brief Registers the property view's required items.
		 * \param factory The factory.
		 */
		static void registerPropertyItems(PropertyViewFactory* factory);

		/*!
		 * \brief Initialize new instance.
		 * \param pipelineItem The pipeline item.
		 * \param parentWidget The parent widget.
		 * \param parentView The parent item.
		 */
		ModelLoaderPropertyView(IPipelineItem* pipelineItem, QWidget* parentWidget, IView* parentView);
	};
}

#endif
