using System;
using System.Collections.Generic;

namespace hw_Farmanov_01._16._2024;

public partial class SummaryOfSalesByYear
{
    public DateTime? ShippedDate { get; set; }

    public int OrderId { get; set; }

    public decimal? Subtotal { get; set; }
}
