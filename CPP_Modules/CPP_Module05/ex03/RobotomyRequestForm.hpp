/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:41:04 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/26 17:06:02 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <random>

class RobotomyRequestForm : public Form
{
private:
    std::string const _target;
public:
    RobotomyRequestForm(std::string target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    std::string getTarget() const;

    virtual void execute(Bureaucrat const &bureaucrat) const throw (NotSignedFormException, GradeTooLowException);
    void action() const;
};

#endif