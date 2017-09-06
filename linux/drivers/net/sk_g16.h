/*-
 *
 * This software may be used and distributed according to the terms
 * of the GNU General Public License, incorporated herein by reference.
 *
 * Module         : sk_g16.h
 * Version        : $Revision: 1.1.1.1 $  
 *
 * Author         : M.Hipp (mhipp@student.uni-tuebingen.de)
 * changes by     : Patrick J.D. Weichmann
 *
 * Date Created   : 94/05/25
 *
 * Description    : In here are all necessary definitions of  
 *                  the am7990 (LANCE) chip used for writing a
 *                  network device driver which uses this chip 
 *
 * $Log: sk_g16.h,v $
 * Revision 1.1.1.1  2010/06/15 01:48:51  ysyoo
 * RTL8196C
 *
 * Revision 1.1.1.1  2007/08/06 10:04:51  root
 * Initial import source to CVS
 *
 * Revision 1.1.1.1  2004/07/28 06:27:25  ysc
 *
 * Initial version
 *
 * Revision 1.1.1.1  2004/07/14 13:34:10  ysy
 *
 *
 * Revision 1.1.1.1  2004/07/13 21:58:18  ysy
 *
 *
 * Revision 1.1.1.1  2004/07/13 15:57:33  ysy
 * no message
 *
 * Revision 1.1.1.2  2003/04/04 01:16:18  david
 * rtl8181 project
 *
 * Revision 1.1.1.1  2003/03/13 07:57:15  david
 *
 * :
 * VS: ----------------------------------------------------------------------
 *
 * Revision 1.1.1.1  2003/03/13 07:57:15  john
 * rtl8181_prj initially build_up
 *
 * Revision 1.1.1.1  2003/03/12 06:25:09  john
 * rtl8181_prj initially build_up
 *
 * Revision 1.1.1.1  2003/03/12 06:19:21  john
 * rtl8181_prj initially build_up
 *
 * Revision 1.1.1.1  2003/03/11 06:59:04  john
 * RTL8181 Initical Check In
 *
 * Revision 1.1.1.1  2002/03/04 11:12:49  carstenl
 * Linux kernel version 2.4.18 from cvs@oss.sgi.com, 4 March, 2002
 *
-*/

#ifndef SK_G16_H

#define SK_G16_H


/*
 * 	Control and Status Register 0 (CSR0) bit definitions
 *
 * (R=Readable) (W=Writeable) (S=Set on write) (C-Clear on write)
 *
 */

#define CSR0_ERR	0x8000	/* Error summary (R) */
#define CSR0_BABL	0x4000	/* Babble transmitter timeout error (RC) */
#define CSR0_CERR	0x2000	/* Collision Error (RC) */
#define CSR0_MISS	0x1000	/* Missed packet (RC) */
#define CSR0_MERR	0x0800	/* Memory Error  (RC) */ 
#define CSR0_RINT	0x0400	/* Receiver Interrupt (RC) */
#define CSR0_TINT       0x0200	/* Transmit Interrupt (RC) */ 
#define CSR0_IDON	0x0100	/* Initialization Done (RC) */
#define CSR0_INTR	0x0080	/* Interrupt Flag (R) */
#define CSR0_INEA	0x0040	/* Interrupt Enable (RW) */
#define CSR0_RXON	0x0020	/* Receiver on (R) */
#define CSR0_TXON	0x0010  /* Transmitter on (R) */
#define CSR0_TDMD	0x0008	/* Transmit Demand (RS) */
#define CSR0_STOP	0x0004 	/* Stop (RS) */
#define CSR0_STRT	0x0002	/* Start (RS) */
#define CSR0_INIT	0x0001	/* Initialize (RS) */

#define CSR0_CLRALL     0x7f00  /* mask for all clearable bits */

/*
 *    Control and Status Register 3 (CSR3) bit definitions
 *
 */

#define CSR3_BSWAP	0x0004	/* Byte Swap (RW) */
#define CSR3_ACON	0x0002  /* ALE Control (RW) */
#define CSR3_BCON	0x0001	/* Byte Control (RW) */

/*
 *	Initialization Block Mode operation Bit Definitions.
 */

#define MODE_PROM	0x8000	/* Promiscuous Mode */
#define MODE_INTL	0x0040  /* Internal Loopback */
#define MODE_DRTY	0x0020  /* Disable Retry */ 
#define MODE_COLL	0x0010	/* Force Collision */
#define MODE_DTCR	0x0008	/* Disable Transmit CRC) */
#define MODE_LOOP	0x0004	/* Loopback */
#define MODE_DTX	0x0002	/* Disable the Transmitter */ 
#define MODE_DRX	0x0001  /* Disable the Receiver */

#define MODE_NORMAL 	0x0000  /* Normal operation mode */

/*
 * 	Receive message descriptor status bit definitions.
 */

#define RX_OWN		0x80	/* Owner bit 0 = host, 1 = lance */
#define RX_ERR		0x40	/* Error Summary */
#define RX_FRAM		0x20	/* Framing Error */
#define RX_OFLO		0x10	/* Overflow Error */
#define RX_CRC		0x08	/* CRC Error */ 
#define RX_BUFF		0x04	/* Buffer Error */
#define RX_STP		0x02	/* Start of Packet */
#define RX_ENP		0x01	/* End of Packet */


/*
 *	Transmit message descriptor status bit definitions.
 */

#define TX_OWN		0x80	/* Owner bit 0 = host, 1 = lance */
#define TX_ERR		0x40    /* Error Summary */
#define TX_MORE		0x10	/* More the 1 retry needed to Xmit */
#define TX_ONE		0x08	/* One retry needed to Xmit */
#define TX_DEF		0x04	/* Deferred */
#define TX_STP 		0x02	/* Start of Packet */
#define TX_ENP		0x01	/* End of Packet */

/*
 *      Transmit status (2) (valid if TX_ERR == 1)
 */

#define TX_BUFF 	0x8000  /* Buffering error (no ENP) */
#define TX_UFLO 	0x4000  /* Underflow (late memory) */
#define TX_LCOL 	0x1000  /* Late collision */
#define TX_LCAR 	0x0400  /* Loss of Carrier */
#define TX_RTRY 	0x0200  /* Failed after 16 retransmissions  */
#define TX_TDR          0x003f  /* Time-domain-reflectometer-value */


/* 
 * Structures used for Communication with the LANCE 
 */

/* LANCE Initialize Block */

struct init_block 
{
  unsigned short mode;     /* Mode Register */
  unsigned char  paddr[6]; /* Physical Address (MAC) */
  unsigned char  laddr[8]; /* Logical Filter Address (not used) */
  unsigned int   rdrp;     /* Receive Descriptor Ring pointer */
  unsigned int   tdrp;     /* Transmit Descriptor Ring pointer */
};


/* Receive Message Descriptor Entry */

struct rmd 
{ 
  union
  {
    unsigned long buffer;     /* Address of buffer */
    struct 
    {
      unsigned char unused[3]; 
      unsigned volatile char status;   /* Status Bits */
    } s;
  } u;
  volatile short blen;        /* Buffer Length (two's complement) */
  unsigned short mlen;        /* Message Byte Count */
};


/* Transmit Message Descriptor Entry */

struct tmd   
{
  union 
  {
    unsigned long  buffer;    /* Address of buffer */
    struct 
    {
      unsigned char unused[3];
      unsigned volatile char status;   /* Status Bits */
    } s;
  } u;
  unsigned short blen;             /* Buffer Length (two's complement) */
  unsigned volatile short status2; /* Error Status Bits */
};

#endif /* End of SK_G16_H */