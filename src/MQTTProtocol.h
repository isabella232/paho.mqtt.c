/*******************************************************************************
 * Copyright (c) 2009, 2012 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    Ian Craggs - initial API and implementation and/or initial documentation
 *******************************************************************************/

#if !defined(MQTTPROTOCOL_H)
#define MQTTPROTOCOL_H

#include "LinkedList.h"
#include "MQTTPacket.h"
#include "Clients.h"

#define MAX_MSG_ID 65535
#define MAX_CLIENTID_LEN 23

typedef struct
{
	int socket;
	Publications* p;
} pending_write;


typedef struct
{
	List publications;
	unsigned int msgs_received;
	unsigned int msgs_sent;
	List pending_writes; /* for qos 0 writes not complete */
} MQTTProtocol;


#include "MQTTProtocolOut.h"

#endif
