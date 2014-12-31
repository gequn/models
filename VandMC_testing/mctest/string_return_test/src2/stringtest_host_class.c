/*----------------------------------------------------------------------------
 * File:  stringtest_host_class.c
 *
 * Class:       host  (host)
 * Component:   stringtest
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "string_return_test_sys_types.h"
#include "LOG_bridge.h"
#include "stringtest_classes.h"

/*
 * instance operation:  rstr
 */
c_t *
stringtest_host_op_rstr( stringtest_host * self)
{
  /* RETURN self.upper */
  {c_t * xtumlOALrv = self->upper;
  return xtumlOALrv;}

}



/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      host  (host)
 * Component:  stringtest
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s stringtest_host_container[ stringtest_host_MAX_EXTENT_SIZE ];
static stringtest_host stringtest_host_instances[ stringtest_host_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_stringtest_host_extent = {
  {0}, {0}, &stringtest_host_container[ 0 ],
  (Escher_iHandle_t) &stringtest_host_instances,
  sizeof( stringtest_host ), stringtest_host_STATE_1, stringtest_host_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      host  (host)
 * Component:  stringtest
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [sending]
 */
static void stringtest_host_act1( stringtest_host *, const Escher_xtUMLEvent_t * const );
static void
stringtest_host_act1( stringtest_host * self, const Escher_xtUMLEvent_t * const event )
{
  stringtest_hostevent2 * rcvd_evt = (stringtest_hostevent2 *) event;
  c_t v_sretval5trv34[ESCHER_SYS_MAX_STRING_LEN];c_t u[ESCHER_SYS_MAX_STRING_LEN];stringtest_device * d;
  /* ASSIGN d = PARAM.d */
  d = rcvd_evt->p_d;
  /* ASSIGN u = buffer::scmp(s1:d.lower, s2:PARAM.s) */
  Escher_strcpy( u, stringtest_buffer_op_scmp(d->lower, rcvd_evt->p_s) );
  /* ASSIGN u = buffer::scmp(s1:self.upper, self.rstr()) */
  Escher_strcpy( u, stringtest_buffer_op_scmp(self->upper, Escher_strcpy( v_sretval5trv34, stringtest_host_op_rstr(self))) );
  /* GENERATE device1:send(s:u, h:self) TO d */
  { stringtest_deviceevent1 * e = (stringtest_deviceevent1 *) Escher_NewxtUMLEvent( d, &stringtest_deviceevent1c );
    Escher_strcpy( e->p_s, u );    e->p_h = self;
    Escher_SendEvent( (Escher_xtUMLEvent_t *) e );
  }
}

/*
 * State 2:  [receiving]
 */
static void stringtest_host_act2( stringtest_host *, const Escher_xtUMLEvent_t * const );
static void
stringtest_host_act2( stringtest_host * self, const Escher_xtUMLEvent_t * const event )
{
  stringtest_hostevent1 * rcvd_evt = (stringtest_hostevent1 *) event;
  c_t v_sretval5trv34[ESCHER_SYS_MAX_STRING_LEN];c_t u[ESCHER_SYS_MAX_STRING_LEN];stringtest_device * d;
  /* ASSIGN d = PARAM.d */
  d = rcvd_evt->p_d;
  /* ASSIGN u = buffer::scmp(s1:d.lower, s2:PARAM.s) */
  Escher_strcpy( u, stringtest_buffer_op_scmp(d->lower, rcvd_evt->p_s) );
  /* ASSIGN u = buffer::scmp(s1:self.upper, self.rstr()) */
  Escher_strcpy( u, stringtest_buffer_op_scmp(self->upper, Escher_strcpy( v_sretval5trv34, stringtest_host_op_rstr(self))) );
  /* GENERATE device2:recv(s:u, h:self) TO d */
  { stringtest_deviceevent2 * e = (stringtest_deviceevent2 *) Escher_NewxtUMLEvent( d, &stringtest_deviceevent2c );
    Escher_strcpy( e->p_s, u );    e->p_h = self;
    Escher_SendEvent( (Escher_xtUMLEvent_t *) e );
  }
}

const Escher_xtUMLEventConstant_t stringtest_hostevent1c = {
  stringtest_DOMAIN_ID, stringtest_host_CLASS_NUMBER, STRINGTEST_HOSTEVENT1NUM,
  ESCHER_IS_INSTANCE_EVENT };

const Escher_xtUMLEventConstant_t stringtest_hostevent2c = {
  stringtest_DOMAIN_ID, stringtest_host_CLASS_NUMBER, STRINGTEST_HOSTEVENT2NUM,
  ESCHER_IS_INSTANCE_EVENT };



/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t stringtest_host_StateEventMatrix[ 2 + 1 ][ 2 ] = {
  /* row 0:  uninitialized state (for creation events) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 1:  stringtest_host_STATE_1 (sending) */
  { stringtest_host_STATE_2, EVENT_CANT_HAPPEN },
  /* row 2:  stringtest_host_STATE_2 (receiving) */
  { EVENT_CANT_HAPPEN, stringtest_host_STATE_1 }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t stringtest_host_acts[ 3 ] = {
    (StateAction_t) 0,
    (StateAction_t) stringtest_host_act1,  /* sending */
    (StateAction_t) stringtest_host_act2  /* receiving */
  };

/*
 * instance state machine event dispatching
 */
void
stringtest_host_Dispatch( Escher_xtUMLEvent_t * event )
{
  Escher_iHandle_t instance = GetEventTargetInstance( event );
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 2 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = stringtest_host_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 2 ) {
        /* Execute the state action and update the current state.  */
        ( *stringtest_host_acts[ next_state ] )( instance, event );
        instance->current_state = next_state;
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
      } else {
        /* empty else */
      }
    }
  }
}

