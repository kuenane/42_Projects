// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Module.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 09:09:03 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/19 16:51:49 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MODULE_HPP
# define MODULE_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
# include <vector>
# include <deque>
# include <SFML/Graphics.hpp>

# include <ft_gkrellm.hpp>
# include <modules/IMonitorModule.hpp>
# include <ft_sfml/RoundedBox.hpp>
# include <ft_sfml/DefaultTextBox.hpp>

namespace ftsf
{
class Module : public sf::Drawable
{
public:
	// * STATICS ******************** //
	static sf::Color const		titleColor;
	static sf::Color const		titleBorderColor;
	static sf::Color const		titleTextColor;
	static sf::Color const		mainColor;
	static sf::Color const		mainBorderColor;
	static sf::Texture			arrowTexture;

	static float const			topBoxHeight;
	static float const			mainBoxContentInset;
	static float const			stringsBottomPadding;
	static float const			ModuleBottomPadding;
	static float const			ArrowSize;
	static float const			ArrowVertPadding;
	static float const			ArrowHorizPadding;	

	static float				calcMainBoxHeight(
		ft::IMonitorModule const &module);
	static float				calcModuleFullHeight(
		ft::IMonitorModule const &module);
	// * CTORS / DTORS ************** //
	Module(const sf::Vector2f &mainBoxSize,
		   ft::IMonitorModule const *refModule);
	virtual ~Module();

	// * MEMBER FUNCTIONS / METHODS * //
	virtual void                draw(sf::RenderTarget& target,
									 sf::RenderStates states) const;
	virtual void                setPosition(const float x, const float y);
	float						getHeight(void) const;
	void						refreshStrings(void);
	void						refreshGraphs(void);
	int							doesCollideArrow(float x, float y);

protected:
private:
	Module(Module const &src);
	Module();
	Module						&operator=(Module const &rhs);

	// * ATTRIBUTES ***************** //
	DefaultTextBox				_topBox;
	RoundedBox					_mainBox;
	ft::IMonitorModule const	*_refModule;
	std::vector<sf::Text>		_stringsFrames;
	sf::VertexArray				_linesFrames;
	sf::VertexArray				_linesBackgroundFrames;

	float						_height;
	sf::Sprite					_arrows[2];

};
//std::ostream					&operator<<(std::ostream &o, Module const &rhs);
}
#endif // ******************************************************** MODULE_HPP //
