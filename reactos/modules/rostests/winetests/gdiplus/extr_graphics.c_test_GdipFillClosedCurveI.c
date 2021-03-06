#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int X; int Y; } ;
typedef  int /*<<< orphan*/ * HDC ;
typedef  int /*<<< orphan*/  GpStatus ;
typedef  int /*<<< orphan*/  GpSolidFill ;
typedef  TYPE_1__ GpPoint ;
typedef  int /*<<< orphan*/  GpGraphics ;
typedef  int /*<<< orphan*/  GpBrush ;
typedef  int /*<<< orphan*/  ARGB ;

/* Variables and functions */
 int /*<<< orphan*/  GdipCreateFromHDC (int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  GdipCreateSolidFill (int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  GdipDeleteBrush (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GdipDeleteGraphics (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GdipFillClosedCurveI (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 int /*<<< orphan*/ * GetDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InvalidParameter ; 
 int /*<<< orphan*/  Ok ; 
 int /*<<< orphan*/  OutOfMemory ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  expect (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hwnd ; 
 int /*<<< orphan*/  ok (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void test_GdipFillClosedCurveI(void)
{
    GpStatus status;
    GpGraphics *graphics = NULL;
    GpSolidFill *brush = NULL;
    HDC hdc = GetDC( hwnd );
    GpPoint points[3];

    points[0].X = 0;
    points[0].Y = 0;

    points[1].X = 40;
    points[1].Y = 20;

    points[2].X = 10;
    points[2].Y = 40;

    /* make a graphics object and brush object */
    ok(hdc != NULL, "Expected HDC to be initialized\n");

    status = GdipCreateFromHDC(hdc, &graphics);
    expect(Ok, status);
    ok(graphics != NULL, "Expected graphics to be initialized\n");

    GdipCreateSolidFill((ARGB)0xdeadbeef, &brush);

    /* InvalidParameter cases: null graphics, null brush */
    /* Note: GdipFillClosedCurveI and GdipFillClosedCurve2I hang in Windows
             when points == NULL, so don't test this condition */
    status = GdipFillClosedCurveI(NULL, NULL, points, 3);
    expect(InvalidParameter, status);

    status = GdipFillClosedCurveI(graphics, NULL, points, 3);
    expect(InvalidParameter, status);

    status = GdipFillClosedCurveI(NULL, (GpBrush*)brush, points, 3);
    expect(InvalidParameter, status);

    /* InvalidParameter cases: invalid count */
    status = GdipFillClosedCurveI(graphics, (GpBrush*)brush, points, 0);
    expect(InvalidParameter, status);

    /* OutOfMemory cases: large (unsigned) int */
    status = GdipFillClosedCurveI(graphics, (GpBrush*)brush, points, -1);
    expect(OutOfMemory, status);

    /* Valid test cases */
    status = GdipFillClosedCurveI(graphics, (GpBrush*)brush, points, 1);
    expect(Ok, status);

    status = GdipFillClosedCurveI(graphics, (GpBrush*)brush, points, 2);
    expect(Ok, status);

    status = GdipFillClosedCurveI(graphics, (GpBrush*)brush, points, 3);
    expect(Ok, status);

    GdipDeleteGraphics(graphics);
    GdipDeleteBrush((GpBrush*)brush);

    ReleaseDC(hwnd, hdc);
}