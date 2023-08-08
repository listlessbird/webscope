import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend,
} from "chart.js"

import type { ChartOptions, ChartData } from "chart.js"
import { useContext, useEffect, useState } from "react"

import { Line } from "react-chartjs-2"
import { WaveContext } from "../context"

ChartJS.register(
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend,
)

export const options: ChartOptions = {
  responsive: true,
}

export function Wave() {
  const { data: ctxData, updateWaveData } = useContext(WaveContext)
  const [data, setData] = useState<ChartData>({
    labels: [],
    datasets: [
      {
        label: "Channel 1",
        data: [],
        fill: false,
        borderColor: "rgb(75, 192, 192)",
        tension: 0.1,
      },
    ],
  })

  useEffect(() => {
    generateWave()
  }, [])

  function generateWave() {
    const labels: ChartData["labels"] = []
    const dataset = data.datasets[0]
    const amplitude = 1
    const frequency = 0.1
    const points = 200
    const period = 1 / frequency

    for (let i = 0; i < points; i++) {
      labels.push(i)
      const x = i
      const phase = (x / points) * period
      const y =
        amplitude * Math.sign(Math.sin(2 * Math.PI * frequency * x + phase))
      dataset.data.push(y)
    }
    console.log({ labels, dataset })
    updateWaveData({ labels, datasets: [dataset] })
    setData((prev) => ({ ...prev, labels }))
  }

  return <Line data={data} options={options} />
}
