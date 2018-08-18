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

#ifndef WIZARDFORWARDINGDELEGATE_H
#define WIZARDFORWARDINGDELEGATE_H

#include "iwizarddynamicdelegate.h"

#include <QVariant>

namespace ysm
{

	//! \brief Implementation of the dynamic delegate, that forwards the data to another delegate.
	class WizardForwardingDelegate : public IWizardDynamicDelegate
	{

	public:

		/*!
		 * \brief Initialize new instance.
		 * \param delegate The delegate to forward to.
		 */
		WizardForwardingDelegate(IWizardDynamicDelegate* delegate);

		//! \brief  Initialize new instance.
		WizardForwardingDelegate();

		//! \brief Destruct instance.
		virtual ~WizardForwardingDelegate();

	public:

		/*!
		 * \brief Grants public access to field registration.
		 * This method should simply forward to the wizard page's corresponding method.
		 * \param name The field's name.
		 * \param widget The field's widget.
		 * \param property The widget's property.
		 */
		void registerDynamicField(const QString& name, QWidget* widget, const char* property = NULL) Q_DECL_OVERRIDE;

		/*!
		 * \brief Returns the field's value.
		 * This method should simply forward to the wizard page's corresponding method.
		 * \param name The field's name.
		 * \return The field's value.
		 */
		QVariant dynamicField(const QString& name) const Q_DECL_OVERRIDE;

		/*!
		 * \brief Returns the prefixed name.
		 * \param name The name.
		 * \return The prefixed name.
		 */
		QString dynamicName(const QString& name) const Q_DECL_OVERRIDE;

		//! \brief The widget's completion state changed.
		void notifyCompleteChanged() Q_DECL_OVERRIDE;

	protected:

		//! \brief The widget's delegate
		IWizardDynamicDelegate* _delegate;
	};

}

#endif // WIZARDFORWARDINGDELEGATE_H
