program Airfoil
    !Analysis of Aerodynamic Characteristics of an Airfoil using Finite Volume Method
    !writting by chiha wissem --polytechnic school of tunisia-2023
    !start date :21/03/2023  end date :
    !chihawissem08@gmail.com 
implicit none
!Airfoil shape parameters  
real :: chord_length                   !chord length (=2*l)
real :: attack_angle                   !angle of attack (in radian)
real :: thickness
real :: camber
real :: edge_angle                     !trailling edge angle 
real :: elongation                     !airfoil elongation = area/length 
real :: radius,edge_location,xsi_e,eta_e
!Flow conditions:   
real :: density,pressure_coefficient 
real :: circulation,air_velocity
!Output parameters: 
real :: lift,drag,lift_to_drag_ratio
!chacacters  variables contains names of otuput data files to be generated 
character(len=40) :: filename  
real ,dimension(:,:) , allocatable :: nodes,airfoil_shape,velocity,pressure
integer :: k                                 !counter for do loops 
real , dimension(1,2) :: z_node ,node_velocity
!start calculation signal input from user 
character(len=1) :: start
     
!------------------------------------------------------------------------------------  
print *, ' '
print *, '**************************************************************************'
print *, '**                                                                      **'
print *, '***********************  WELCOME TO THE AIRFOIL  *********************'
print *, '***********  AN AUTOMATED AERODYNAMIC OPTIMISATION SOFTWARE  *************'
print *, '**                                                                      **'
print *, '*********************   written by CHIHA WISSEM  *******************'
print *, '**************************************************************************'
print *, ''
call sleep(1)
start='n'
do while(start=='n')
print *, '--------------------------------------------------------------------------' 
print * , '---------------------Airfoil Shape Parameters----------------------------'
print * ,' -------------------------------------------------------------------------'
chord_length=readData(' chord length ',' (real : positive value)' )
attack_angle=readData(' angle of attack ',' (real : positive value : in radian)' )
thickness=readData(' thickness ',' (real : positive value)' )
camber=readData(' camber',' (real : positive value) ' )
edge_angle=readData(' edge angle ',' (real : positive value : in radian)' )
elongation=readData(' elongation ',' (real : positive value)' )
print * ,'--------------------------------------------------------------------------'
print * ,'--------------------------Flow Conditions---------------------------------'
print * ,'--------------------------------------------------------------------------'
density=readData(' fluid density ',' (real : positive value)')
air_velocity=readData(' air velocity ',' (real : positive value )')

print *, 'Start Calculations ?[y/n]'
read(*,*) start
if ( start=='y' ) then
    

 
print * ,'Setting up transformation variables....'
radius=chord_length *sqrt((1+thickness)**2+camber**2)
edge_location=asin(camber/radius) 
eta_e=chord_length*camber
xsi_e=-chord_length*thickness
print * ,'Generating Control nodes....' 
nodes=generate_nodes(chord_length,edge_location,96,xsi_e,eta_e)
print * , 'Calculating airfoil shape using karaman trefftz transformation....'
allocate(airfoil_shape(size(nodes,1),2))
do k = 1,size(nodes,1)
    z_node=karaman_trefftz_transform([nodes(k,1),nodes(k,2)],edge_angle,chord_length)
    airfoil_shape(k,1)=z_node(1,1)
    airfoil_shape(k,2)=z_node(1,2)
end do
print * ,'Writing results to output file.... '
filename ='airfoil_shape.csv'
open(10,file=filename,status ='replace')
do k = 1, size(airfoil_shape,1)
    write(10,'(2F7.2)') airfoil_shape(k,1) ,airfoil_shape(k,2)
end do
close(10)

print * ,'Calculating circulation coefficient....'
circulation=calculate_cirulation(air_velocity,radius,edge_location,attack_angle)
print *, 'Calculating velocity at airfoil surface....'
allocate(velocity(size(airfoil_shape,1),2))
do k = 1,size(airfoil_shape,1)
    node_velocity=calculate_velocity(radius,air_velocity,attack_angle,circulation,edge_angle,nodes(k,1),nodes(k,2))
    velocity(k,1)=node_velocity(1,1)
    velocity(k,2)=node_velocity(1,2)
end do
print *, 'Writing results to output file....'
filename='velocity.csv'
open(11,file=filename,status='replace')
do k = 1, size(airfoil_shape,1)
    write(11,'(2F7.2)')  velocity(k,1) ,velocity(k,2)
    
end do
close(11)
print * ,'Calculating pressure coefficient at surface.... '
allocate(pressure(size(nodes,1),1))
do k = 1,size(nodes,1)
    pressure(k,1)=presure_coeff(velocity(k,1),velocity(k,2),air_velocity)
end do
print *, 'Writing results to output file....'
filename='pressure.csv'
open(12,file=filename,status='replace')
 do k = 1, size(pressure,1)
    write(12,'(1F7.2)') pressure(k,1)
 end do
close(12)

print * , 'Calculating airfoil lift....'
lift=calculate_lift(density,air_velocity,circulation)
print *, ''
print *, 'CALCULATIONS DONE SUCCESSFULLY !! :SEE OUTPUT FILES !!'
filename='Airfoil_Analysis_Report.txt'
open(13,file=filename,status='replace')
write(13,*) '****************************************************************'
write(13,*) '*****************Airfoil Analysis Report ********************'
write(13,*) '****************************************************************'
write(13,*)'CHIHA WISSEM'
write(13,*) ''
write(13,*)'Airfoil Parameters:'
write(13,*)'chord | angle of attack | thickness | camber | edge_angle |edge location |'
write(13,'(6F7.2)') chord_length,attack_angle,thickness,camber,edge_angle,edge_location
write(13,*)''
write(13,*) 'Flow Properties:'
write(13,*)'density | airspeed |'
write(13,'(2F7.2)') density, air_velocity
write(13,*) 'Velocity Calculation: see velocity.csv file !'
write(13,*)''
write(13,*)'Pressure Calculation: pressure coefficient'
write(13,*)'max | min |'
write(13,'(2F7.2)') maxval(pressure) ,minval(pressure)
write(13,*) ''
write(13,*) 'Airfoil Lift: '
write(13,'(F7.2)') lift

close(13)
call sleep(10)

end if
end do

!*************************************************************************************
!--------------------------functions and subroutines---------------------------------- 
!*************************************************************************************
contains

function readData(var_input,condition) result(var_output)
    implicit none
    character(len=*) :: var_input,condition
    real :: var_output
    print * , 'enter'//var_input//condition 
    read(*,*) var_output
end function readData 

!-----------------------------------------------------------------------------------------
function generate_nodes(r,trailing_edge,node_number,x_center,y_center) result(node_matrix)
    implicit none 
    real :: r, pi=3.141592654                            !circle radius 
    real :: x_center,y_center                            !circle center coordinate
    real :: trailing_edge,step_angle                     !in radian                                          
    integer ::node_number,i                              !number of control nodes ,counter 
    real ,dimension(:,:), allocatable :: node_matrix  

    step_angle=2*pi/node_number
    allocate(node_matrix(node_number+1,2))
    node_matrix(1,1)=r*cos(trailing_edge)+x_center
    node_matrix(1,2)=r*sin(-trailing_edge)+y_center
    do i = 1,node_number
        node_matrix(i+1,1)=r*cos(i*step_angle-trailing_edge)+x_center
        node_matrix(i+1,2)=r*sin(i*step_angle-trailing_edge)+y_center
    end do
end function generate_nodes

!--------------------------------------------------------------------------------------------------
function karaman_trefftz_transform(circle_node,tau,r) result(shape_node)
    implicit none 
    real ,dimension(1,2) :: circle_node ,shape_node
    real ::r,tau,pi=3.141592654
    integer :: n 
    complex :: zeta, z
 
    zeta=complex(circle_node(1,1),circle_node(1,2))
    n=nint(2-tau/pi)
    z=n*r*((zeta+r)**n+(zeta-r)**n)/((zeta+r)**n-(zeta-r)**n)
    shape_node(1,1)=real(z)
    shape_node(1,2)=aimag(z) 
end function  karaman_trefftz_transform

!----------------------------------------------------------------------------------------------------
function calculate_velocity(r,airspeed,attack,gamma,tau,zeta_x,zeta_y) result(v)
    implicit none
    ! zeta_x and zeta_y are points in the zeta plane of the circle   surface 
    real :: arg,gamma,attack,zeta_x,zeta_y,airspeed,r,tau,pi=3.141592654
    integer :: n
    real ,dimension(1,2) :: v
    complex :: g ,zeta ,w,z, attack_cmplx,stream ,velocity_potential,ww
    !compute the derivative of the karaman trefftz transformation 
    n=nint(2-tau/pi)
    zeta=complex(zeta_x,zeta_y)
    g=4*n**2*(((zeta+r)*(zeta-r))**(n-1))/((zeta+r)**n-(zeta-r)**n)**2
    !compute the complex velocity around the mapped circle 
    arg=atan2(zeta_x,zeta_y)
    z=r*complex(cos(arg),sin(arg))
    attack_cmplx=complex(cos(attack),-sin(attack))
    velocity_potential=airspeed*(attack_cmplx-r**2*conjg(attack_cmplx)/(z**2))
    stream =gamma/(2*pi*z)

    w=velocity_potential+complex(-aimag(stream),real(stream))
    !compute the complex velocity potentiel around the airfoil surface in the z-plane
    ww=g*w
    !output compenent of velocity 
    v(1,1)=real(ww)
    v(1,2)=aimag(ww)
end function calculate_velocity

!-----------------------------------------------------------------------------------------------------
function presure_coeff(u,v,airspeed) result(cp)
    implicit none 
    real :: cp ,airspeed,vel
     real :: u,v 
     cp=1-(u**2+v**2)/(airspeed**2)
end function presure_coeff
!---------------------------------------------------------------------------------------------------
function calculate_cirulation(airspeed,a,edge,attack) result(gamma)
    implicit none
    real :: gamma                   !flow circulation value 
    real :: airspeed ,ro,a,attack,pi=3.141592654
    real :: edge 
   gamma=4*airspeed*pi*a*sin(attack+edge)
end function  calculate_cirulation 

!---------------------------------------------------------------------------------------------------
function calculate_lift(ro,airspeed,gamma) result(l)
    implicit none 
    real :: gamma ,ro ,airspeed   ! input parameters : circulation , density ,Vinfinity
    real :: l                     ! output lift coefficient
    l=ro*gamma*airspeed 
end function  calculate_lift 

end program Airfoil 
    
   