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

#ifndef VEC4UNIFORMBLOCK_H
#define VEC4UNIFORMBLOCK_H

#include "uniformblock.h"

namespace ysm
{
	class Vec4UniformBlock : public UniformBlock
	{
		Q_OBJECT

	public:
		static const BlockType block_type{BlockType::Uniform_Vec4};

		using uniform_value_type = QVector4D;

	public:
		// Construction
		explicit Vec4UniformBlock(Pipeline* parent);

	public:
		/**
		 * @brief Gets the uniform value
		 */
		Vec4Property* getValue();

	public:
		// Raw data functions
		unsigned int getOutputSize(IPort* port) const override;
		QByteArray retrieveUniformData(IPort* port) const override;

	protected:
		void createProperties() override;

	private:
		Vec4Property* _value{nullptr};
	};
}

#endif
