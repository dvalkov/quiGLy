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

#include "texturesamplerpropertyview.h"
#include "data/blocks/texturesamplerblock.h"

using namespace ysm;

TextureSamplerPropertyView::TextureSamplerPropertyView(IPipelineItem* pipelineItem, QWidget* parentWidget,
													   IView* parentView):
	PipelineItemPropertyView(pipelineItem, parentWidget, parentView)
{
	//set Filter Layout
	setPropertyGroup(pipelineItem->getProperty<EnumProperty>(PropertyID::TextureBase_MagFilter), "Filtering");
	setPropertyGroup(pipelineItem->getProperty<EnumProperty>(PropertyID::TextureBase_MinFilter), "Filtering");
	setPropertyGroup(pipelineItem->getProperty<FloatProperty>(PropertyID::TextureBase_Anisotropy), "Filtering");
	setPropertyGroup(pipelineItem->getProperty<FloatProperty>(PropertyID::TextureBase_MinLOD), "Filtering");
	setPropertyGroup(pipelineItem->getProperty<FloatProperty>(PropertyID::TextureBase_MaxLOD), "Filtering");

	//Set Wrap Layout
	setPropertyGroup(pipelineItem->getProperty<EnumProperty>(PropertyID::TextureBase_WrapModeR), "WrapMode");
	setPropertyGroup(pipelineItem->getProperty<EnumProperty>(PropertyID::TextureBase_WrapModeS), "WrapMode");
	setPropertyGroup(pipelineItem->getProperty<EnumProperty>(PropertyID::TextureBase_WrapModeT), "WrapMode");

	//Set Comparing
	setPropertyGroup(pipelineItem->getProperty<EnumProperty>(PropertyID::TextureBase_CompareFunc), "Comparing");
	setPropertyGroup(pipelineItem->getProperty<BoolProperty>(PropertyID::TextureBase_CompareMode), "Comparing");
}
