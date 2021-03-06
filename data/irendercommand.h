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

#ifndef IRENDERCOMMAND_H
#define IRENDERCOMMAND_H

#include "ipipelineitem.h"
#include "rendercommands/rendercommandtype.h"

namespace ysm
{
	class IBlock;

	/// @brief Interface for render commands.
	class IRenderCommand : public IPipelineItem
	{
	public:

		/// @brief Destruct instance.
		virtual ~IRenderCommand() { }

	public:

		/**
		 * @brief Gets the render command's type.
		 * @return The render command's type.
		 */
		virtual RenderCommandType getCommand() const = 0;

		/**
		 * @brief Retrieves the assigned block (if any).
		 * @param The assigned block or null.
		 */
		virtual IBlock* getAssignedBlock() const = 0;

		/**
		 * @brief Assigns this render command to a block.
		 * @param block The block.
		 */
		virtual void assignBlock(IBlock* block) = 0;

		/**
		 * @brief Called before a new block is assigned to this command.
		 * @param block The block.
		 * @param denialReason Returns a possible reason for failure.
		 * @return True, if block assignment is possible.
		 */
		virtual bool canAcceptBlockAssignment(IBlock* block, QString& denialReason) = 0;

	protected:

		/// @brief Initialize new instance.
		IRenderCommand() { }
	};
}

#endif
