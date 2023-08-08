import React from "react"
import { Wave } from "./Wave"

export default function PlotView() {
  return (
    <div className="wrap-plot-view w-full mt-12 flex flex-col items-center max-w-[55rem] ml-auto mr-auto">
      <div className="min-w-[16rem] w-full bg-[#1b1b1b] border-2 border-white rounded">
        <Wave />
      </div>
      <div className="wrap-controls mt-2 flex gap-1 justify-end self-end w-full">
        <PlotControl controlName="View Saved" className="mr-auto" />
        <PlotControl controlName="Reset" />
        <PlotControl controlName="Save" />
      </div>
    </div>
  )
}

interface IPlotControl extends React.HTMLAttributes<HTMLButtonElement> {
  controlName: string
}

const PlotControl = ({ controlName, className: classes }: IPlotControl) => {
  return (
    <button
      className={`${classes} text-xs font-bold bg-zinc-300 bg-opacity-0 rounded-lg border-2 border-white p-2 font-Poppins`}
    >
      {controlName}
    </button>
  )
}
