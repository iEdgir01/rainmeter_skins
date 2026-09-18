; 20-minute history cells. Generated - one per minute slot.
;
; The parent regex captures "hist" as 20 single-char groups (indices 15..34)
; rather than one 20-char string. This is deliberate: RegExp2 is NOT honoured
; on a child WebParser measure - only the parent RegExp runs, and children
; just index into its captures. Trying to re-extract a character per cell
; silently substituted all 20 chars into one concatenated colour string,
; which Rainmeter read as "64,214,133<garbage>" and rendered cyan.
;
;   F=fibre  L=lte  X=down  .=no data

[MeasureHist0]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=15
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist0]
Meter=Shape
X=(#Pad# + 0)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist0] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist1]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=16
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist1]
Meter=Shape
X=(#Pad# + 10)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist1] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist2]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=17
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist2]
Meter=Shape
X=(#Pad# + 20)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist2] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist3]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=18
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist3]
Meter=Shape
X=(#Pad# + 30)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist3] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist4]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=19
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist4]
Meter=Shape
X=(#Pad# + 40)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist4] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist5]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=20
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist5]
Meter=Shape
X=(#Pad# + 50)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist5] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist6]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=21
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist6]
Meter=Shape
X=(#Pad# + 60)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist6] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist7]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=22
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist7]
Meter=Shape
X=(#Pad# + 70)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist7] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist8]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=23
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist8]
Meter=Shape
X=(#Pad# + 80)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist8] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist9]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=24
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist9]
Meter=Shape
X=(#Pad# + 90)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist9] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist10]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=25
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist10]
Meter=Shape
X=(#Pad# + 100)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist10] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist11]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=26
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist11]
Meter=Shape
X=(#Pad# + 110)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist11] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist12]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=27
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist12]
Meter=Shape
X=(#Pad# + 120)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist12] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist13]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=28
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist13]
Meter=Shape
X=(#Pad# + 130)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist13] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist14]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=29
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist14]
Meter=Shape
X=(#Pad# + 140)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist14] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist15]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=30
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist15]
Meter=Shape
X=(#Pad# + 150)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist15] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist16]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=31
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist16]
Meter=Shape
X=(#Pad# + 160)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist16] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist17]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=32
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist17]
Meter=Shape
X=(#Pad# + 170)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist17] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist18]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=33
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist18]
Meter=Shape
X=(#Pad# + 180)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist18] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1

[MeasureHist19]
Measure=Plugin
Plugin=WebParser
URL=[MeasureHealth]
StringIndex=34
Substitute="F":"64,214,133","L":"198,142,255","X":"242,92,92",".":"255,255,255,12"

[MeterHist19]
Meter=Shape
X=(#Pad# + 190)
Y=#HistY#
Shape=#CellShape# | Fill Color [MeasureHist19] | StrokeWidth 0
Hidden=(#Expanded# = 0 ? 1 : 0)
DynamicVariables=1
