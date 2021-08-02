%% Vandermonde Matrix System for polynomial interpolation

%% Introduction
% <html>
% In this lab, we will learn how to solve the Vandermonde matrix system to
% find the coefficients of an interpolating polynomial.  We will also see
% how the matlab command <span class="var">polyfit</span> can be used to
% obtain the same set of coefficients.
% </html>

%% Generate the data 
clear all;
close all;
N = 10;  % We will try to fit a tenth degree polynomial
x = linspace(-1,1,N+1)';
a = 3;
b = 8; 
y = a + (b-a)*rand(N+1,1);   % Generate random numbers in [a,b]

plot(x,y,'k.','markersize',30);
snapnow;

%% Solving the Vandermonde system 
% <html>
% Solve the Vandermonde system using <span class="var">vander</span>
% </html>

V = vander(x);
a = V\y;

%%
% Plot the results of the Vandermonde system
xs = linspace(-1,1,100);
ys = polyval(a,xs);

plot(xs,ys,'r','linewidth',1);

hold on;
plot(x,y,'k.','markersize',30);
title('Using vander','fontsize',18);
snapnow;

%% Using the polynomial interpolation available in Matlab. 
% <html>
% Use the Matlab function <span class="var">polyfit</span>
% </html>
%

p = polyfit(x,y,N);     % Supply the degree of the polynomial
ys = polyval(p,xs);

plot(xs,ys,'ko','linewidth',1); % Plot using the 'circle' symbol
title('Using polyfit','fontsize',18);
snapnow;

%% Exercises
% <html>
% <div class="prob">
% For each of the following problems, use the <span class="key">vander</span>
% function to answer the questions.  Plot the data points and the
% curve you find. 
% <ol class="ex">
% <li> Find the slope and the y-intercept of the line that passes through
% the two points <span class="inlinemath">$(-3.2, 1.2)$</span> and <span
% class="key">$(5.4,-4.3)$</span>.  </li>
% <li>Find the maximum value of the parabola that passes through the three
% points
% <span class="displaymath">$$(-3.2, 4.5), \quad (1.2,6.1), \quad 
% (6.1,-3.4)$$</span>
% </ol>
% </div>
% </html>

%% Download this file
% <html>
% Download the file that created this lab <a
% href="../lab_9.m">here</a>
% </html>
