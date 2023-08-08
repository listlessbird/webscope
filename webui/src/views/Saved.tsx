import Card from "../components/Card"
import Wrapper from "../components/Wrapper"

export default function Saved() {
  return (
    <Wrapper>
      <h2 className="text-[1.5rem] font-bold font-Poppins">
        Saved Responses :
      </h2>
      <div
        className="
        card-Wrapper
        grid
        gap-4
        grid-cols-1
        sm:grid-cols-2
        md:grid-cols-3
        lg:grid-cols-4
        xl:grid-cols-5
      "
      >
        {/* Fetch from the db and populate responses here : */}

        <Card />
        <Card />
        <Card />
        <Card />
        <Card />
        <Card />
      </div>
    </Wrapper>
  )
}
