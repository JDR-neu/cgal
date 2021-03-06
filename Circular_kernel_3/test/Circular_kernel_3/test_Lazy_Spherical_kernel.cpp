// Copyright (c) 2008  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
//
// $URL$
// $Id$
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
//
// Author(s) : Monique Teillaud, Sylvain Pion, Pedro Machado

// Partially supported by the IST Programme of the EU as a
// STREP (FET Open) Project under Contract No  IST-006413
// (ACS -- Algorithms for Complex Shapes)

#include <CGAL/Spherical_kernel_3.h>
#include <CGAL/Algebraic_kernel_for_spheres_2_3.h>
#include <CGAL/_test_sphere_predicates.h>
#include <CGAL/_test_sphere_constructions.h>
#include <CGAL/_test_sphere_compute.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/_test_functionalities_on_sphere.h>


int main()
{
  typedef CGAL::Exact_predicates_exact_constructions_kernel Linear_k1;
  typedef Linear_k1::FT FT;
  typedef CGAL::Algebraic_kernel_for_spheres_2_3<FT>          Algebraic_k1;
  typedef CGAL::Spherical_kernel_3<Linear_k1,Algebraic_k1>    SK1;

  SK1 sk1;
  _test_spherical_kernel_predicates(sk1);
  _test_spherical_kernel_construct(sk1);
  _test_spherical_kernel_compute(sk1);
  test_functionalities_on_a_reference_sphere<SK1>(SK1::Point_3(4.5,1.2,0.7));
  return 0;
}
