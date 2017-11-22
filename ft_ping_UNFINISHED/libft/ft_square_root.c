/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 11:45:16 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/09 11:46:21 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long		ft_square_root(long n)
{
  long long		prev;
  long long		x;

  prev = ~((unsigned long long) 1 << 63);
  x = n;
  if (x > 0)
  {
    while (x < prev)
    {
      prev = x;
      x = (x + (n / x)) / 2;
    }
  }
  return ((long)x);
	return (n * n);
}
