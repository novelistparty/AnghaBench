#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct rt2860_tx_ring {scalar_t__ next; scalar_t__ cur; scalar_t__ queued; struct rt2860_tx_data** data; } ;
struct rt2860_tx_data {int /*<<< orphan*/ * ni; int /*<<< orphan*/ * m; int /*<<< orphan*/  map; } ;
struct rt2860_softc {int /*<<< orphan*/  data_pool; int /*<<< orphan*/  txwi_dmat; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_DMASYNC_POSTWRITE ; 
 int RT2860_TX_RING_COUNT ; 
 int /*<<< orphan*/  SLIST_INSERT_HEAD (int /*<<< orphan*/ *,struct rt2860_tx_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_dmamap_sync (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_dmamap_unload (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ieee80211_free_node (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  m_freem (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  next ; 

void
rt2860_reset_tx_ring(struct rt2860_softc *sc, struct rt2860_tx_ring *ring)
{
	struct rt2860_tx_data *data;
	int i;

	for (i = 0; i < RT2860_TX_RING_COUNT; i++) {
		if ((data = ring->data[i]) == NULL)
			continue;	/* nothing mapped in this slot */

		if (data->m != NULL) {
			bus_dmamap_sync(sc->txwi_dmat, data->map,
			    BUS_DMASYNC_POSTWRITE);
			bus_dmamap_unload(sc->txwi_dmat, data->map);
			m_freem(data->m);
			data->m = NULL;
		}
		if (data->ni != NULL) {
			ieee80211_free_node(data->ni);
			data->ni = NULL;
		}

		SLIST_INSERT_HEAD(&sc->data_pool, data, next);
		ring->data[i] = NULL;
	}

	ring->queued = 0;
	ring->cur = ring->next = 0;
}