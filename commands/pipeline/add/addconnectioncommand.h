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

#ifndef ADDCONNECTIONCOMMAND_H
#define ADDCONNECTIONCOMMAND_H

#include "../../uidatachangingcommand.h"
#include "data/ipipeline.h"
#include "data/iblock.h"
#include "data/iport.h"

#include <QObject>

namespace ysm
{
	//! \brief Command that creates a new connection.
	class AddConnectionCommand : public UIDataChangingCommand
	{
	public:

		/*!
		 * \brief Initialize new instance. Source and target port are exchanged, if in/out does not match.
		 * \param sourcePort The source port.
		 * \param targetPort The target port.
		 */
		AddConnectionCommand(IPort* sourcePort, IPort* targetPort);

		/*!
		 * \brief Execute the command.
		 * \return True, on success.
		 */
		bool execute() Q_DECL_OVERRIDE;

		/*!
		 * \brief Execute the command.
		 * \return True, on success.
		 */
		bool undo() Q_DECL_OVERRIDE;

		/*!
		 * \brief Returns the created connection.
		 * \return The created connection.
		 */
		IConnection* getConnection() const;

	private:

		//! \brief The pipeline.
		IPipeline* _pipeline;

		//! \brief The source port.
		IPort* _sourcePort;

		//! \brief The target port.
		IPort* _targetPort;

		//! \brief The created connection.
		IConnection* _createdConnection;

		//! \brief Indicating incorrect setup.
		bool _canExecute;
	};

}

#endif // ADDCONNECTIONCOMMAND_H
