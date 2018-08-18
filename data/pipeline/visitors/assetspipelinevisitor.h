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

#ifndef ASSETSPIPELINEVISITOR_H
#define ASSETSPIPELINEVISITOR_H

#include "pipelinevisitor.h"

#include <QStringList>

namespace ysm
{
	class PropertyList;

	/**
	 * @brief Pipeline visitor to work with assets/files
	 */
	class AssetsPipelineVisitor : public PipelineVisitor
	{
	public:
		// Construction
		explicit AssetsPipelineVisitor();

	public:
		QStringList getAssetFiles() const;

	public:
		bool blockVisited(Block* block) override;
		bool portVisited(Port* port) override;
		bool connectionVisited(Connection* connection) override;
		bool renderCommandVisited(RenderCommand* command) override;

	private:
		/**
		 * @brief Assembles all filenames in a property list
		 */
		void processProperties(PropertyList* properties);

	private:
		QStringList _assetFiles;
	};
}

#endif
